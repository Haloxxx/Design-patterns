#include <iostream>
#include <vector>

class IKlawisz {
    public:
    char key;
    IKlawisz(char button)
    {
        key = button;
    }

    virtual void monitor(char key_pressed) {std::cout<<"test\n";};
};



class Klawisz : public IKlawisz {

    public:
        char key;
        Klawisz(char button):IKlawisz(button){
            key = button;
            //std::cout<<key<<'\n';
        }

        void monitor(char key_pressed){
            //std::cout<<"W klawiszu\n";
            if (key_pressed == key){
                std::cout<<"Wciśnięto klawisz "<<key<<'\n';
            }
        }
};

class NamiastkaKlawisz : public IKlawisz {
    public:
    char key;
    Klawisz* klawisz;
    
    NamiastkaKlawisz(char button):IKlawisz(button)
    {
        key = button;
    }

    void monitor(char key_pressed) override {
        //std::cout<<"W namiastce\n";
        //if (key_pressed >= 'q' && key_pressed <= 'p'){
        if (key_pressed == 'q'){
            if (klawisz == nullptr){
                klawisz = new Klawisz(key_pressed);
            }
            klawisz->monitor(key_pressed);
        }
    }
};

class Klawiatura {
    private:
        Klawiatura(){};
        static Klawiatura* instance;
        char* key_pressed;
        std::vector<IKlawisz*> klawisze;

    public:

        Klawiatura(Klawiatura &other) = delete;
    
        void operator=(const Klawiatura &) = delete;

        static Klawiatura *get_instance(); 

        void add_button(IKlawisz* button){
            //std::cout<<button->key+'\n';
            //std::cout<<"dodaje"<<button->key<<"\n";
            klawisze.push_back(button);
        }

        void push_button(char button)
        {
            for (int i = 0; i < klawisze.size(); ++i)
            {
                //std::cout<<klawisze[i].key<<'\n'; 
                if (klawisze[i]->key == button)
                {
                    //std::cout<<"klikam\n";
                    klawisze[i]->monitor(button);
                }
            }
        }
};

Klawiatura* Klawiatura::instance= nullptr;

Klawiatura *Klawiatura::get_instance(){
    if (instance == nullptr){
        instance = new Klawiatura();
    }
    return instance;
}


int main()
{
    Klawiatura* klawiatura1 = Klawiatura::get_instance();

    klawiatura1->add_button(new NamiastkaKlawisz('a'));
    klawiatura1->add_button(new NamiastkaKlawisz('q'));

    klawiatura1->push_button('a');
    klawiatura1->push_button('q');
    std::cout<<"?\n";
    
}