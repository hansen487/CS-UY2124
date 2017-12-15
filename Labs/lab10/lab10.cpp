#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

class Instrument{
public:
        virtual void makeSound() const = 0;
        virtual void play() const = 0;
};

class Percussion : public Instrument{
public:
    void makeSound() const{
        Instrument::makeSound();
        cout << "hit me!" << endl;
    }
    void play();
};

void Instrument::makeSound() const{
    cout << "To make a sound...";
}

class Brass : public Instrument{
public:
    Brass(unsigned mouthpiece) : mouthpiece(mouthpiece) {}
    void makeSound() const{
        Instrument::makeSound();
        cout << "blow on a mouthpiece of size " << mouthpiece << endl;
    }
    void play() const{};
private:
    unsigned mouthpiece;
};

class String : public Instrument{
public:
    String( unsigned pitch) : pitch(pitch) {}
    void makeSound() const{
        Instrument::makeSound();
        cout << "bow a string with pitch " << pitch << endl;
    }
    void play() const{};
private:
    unsigned pitch;
};

class Drum : public Percussion {
public:
    void play() const{
        cout << "Boom";
    }
};
class Cello : public String {
public:
    Cello( unsigned pitch) : String(pitch) {}
    void makeSound() const{
        String::makeSound();
    }
    void play() const{
        cout << "Squawk";
    }
};
class Cymbal : public Percussion {
public:
    void play() const{
        cout << "Crash";
    }
};
class Trombone : public Brass {
public:
    Trombone( unsigned mouthpiece) : Brass(mouthpiece) {}
    void makeSound() const{
        Brass::makeSound();
    }
    void play() const{
        cout << "Blat";
    }
};

class Trumpet : public Brass{
public:
    Trumpet (unsigned mouthpiece) : Brass(mouthpiece) {}
    void makeSound() const{
        Brass::makeSound();
    }
    void play() const{
        cout << "Toot";
    }
};
class Violin : public String {
public:
    Violin( unsigned pitch) : String(pitch) {}
    void makeSound() const{
        String::makeSound();
    }
    void play() const{
        cout << "Screech";
    }
};

class Musician {
public:
    Musician() : instr(nullptr) {}
    void acceptInstr(Instrument& i) { instr = &i; }
    Instrument* giveBackInstr() {
        Instrument* tmp(instr);
        instr = nullptr;
        return tmp;
    }
    void testPlay() const {
        if(instr) {instr->makeSound();}
        else {cerr << "have no instr\n";}
    }
    void play() const{
        if (instr != nullptr){
            instr -> play();
        }
    }
private:
    Instrument* instr;
};

class MILL{
public:
    void receiveInstr(Instrument& instr){
        int counter = 0;
        while (counter < instruments.size() && instruments[counter] != nullptr){
            counter++;
        }
        if (counter < instruments.size()){
            instruments[counter] = &instr;
        }
        else{
            instruments.push_back(&instr);
        }
    }
    void dailyTestPlay() const{
        for (Instrument* instrument: instruments){
            if (instrument != nullptr){
                instrument -> makeSound();
            }
        }
    }
    Instrument* loanOut(){
        if (instruments.size() == 0){
            return nullptr;
        }
        else{
            int counter = 0;
            while (instruments[counter] == nullptr){
                counter++;
            }
            Instrument* address = instruments[counter];
            instruments[counter] = nullptr;
            return address;
        }
    }
private:
    vector<Instrument*> instruments;
};

class Orch{
public:
    void addPlayer(Musician& player) {
        musicians.push_back(&player);
    }
    void play(){
        for (Musician* musician: musicians){
            musician -> play();
        }
        cout << endl;
    }
private:
    vector<Musician*> musicians;
};

//PART ONE

// PART TWO
int main() {
    // The initialization phase

    Drum drum;
    Cello cello(673);
    Cymbal cymbal;
    Trombone tbone(4);
    Trumpet trpt(12);
    Violin violin(567);

    MILL mill;
    mill.receiveInstr(trpt);
    mill.receiveInstr(violin);
    mill.receiveInstr(tbone);
    mill.receiveInstr(drum);
    mill.receiveInstr(cello);
    mill.receiveInstr(cymbal);

    Musician bob;
    Musician sue;
    Musician mary;
    Musician ralph;
    Musician jody;
    Musician morgan;

    Orch orch;



    // THE SCENARIO

    //Bob joins the orchestra without an instrument.
    orch.addPlayer(bob);

    //The orchestra performs
    cout << "orch performs\n";
    orch.play();

    //Sue gets an instrument from the MIL2 and joins the orchestra.
    sue.acceptInstr(*mill.loanOut());
    orch.addPlayer(sue);

    //Ralph gets an instrument from the MIL2.
    ralph.acceptInstr(*mill.loanOut());

    //Mary gets an instrument from the MIL2 and joins the orchestra.
    mary.acceptInstr(*mill.loanOut());
    orch.addPlayer(mary);

    //Ralph returns his instrument to the MIL2.
    mill.receiveInstr(*ralph.giveBackInstr());

    //Jody gets an instrument from the MIL2 and joins the orchestra.
    jody.acceptInstr(*mill.loanOut());
    orch.addPlayer(jody);

    // morgan gets an instrument from the MIL2
    morgan.acceptInstr(*mill.loanOut());

    //The orchestra performs.
    cout << "orch performs\n";
    orch.play();

    //Ralph joins the orchestra.
    orch.addPlayer(ralph);

    //The orchestra performs.
    cout << "orch performs\n";
    orch.play();

    // bob gets an instrument from the MIL2
    bob.acceptInstr(*mill.loanOut());

    // ralph gets an instrument from the MIL2
    ralph.acceptInstr(*mill.loanOut());

    //The orchestra performs.
    cout << "orch performs\n";
    orch.play();

    //Morgan joins the orchestra.
    orch.addPlayer(morgan);

    //The orchestra performs.
    cout << "orch performs\n";
    orch.play();

} // main

