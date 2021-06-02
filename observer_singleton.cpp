#include <iostream>
#include <vector>

class Klawisz {

    public:
        char key;
        Klawisz(char button){
            key = button;
            //std::cout<<key<<'\n';
        }

        void monitor(char key_pressed){
            
            if (key_pressed == key){
                std::cout<<"Wciśnięto klawisz "<<key<<'\n';
            }
        }
};

class Klawiatura {
    private:
        Klawiatura(){};
        static Klawiatura* instance;
        char* key_pressed;
        std::vector<Klawisz> klawisze;

    public:

        Klawiatura(Klawiatura &other) = delete;
    
        void operator=(const Klawiatura &) = delete;

        static Klawiatura *get_instance(); 

        void add_button(Klawisz* button){
            //std::cout<<button->key+'\n';
            klawisze.push_back(*button);
        }

        void push_button(char button)
        {
            for (int i = 0; i < klawisze.size(); ++i)
            {
                if (klawisze[i].key == button)
                {
                    klawisze[i].monitor(button);
                }
            }
        }
};

Klawiatura* Klawiatura::instance= nullptr;;

Klawiatura *Klawiatura::get_instance(){
    if (instance == nullptr){
        instance = new Klawiatura();
    }
    return instance;
}


int main()
{
    Klawiatura* klawiatura1 = Klawiatura::get_instance();

    klawiatura1->add_button(new Klawisz('a'));
    klawiatura1->add_button(new Klawisz('b'));
    klawiatura1->add_button(new Klawisz('c'));
    klawiatura1->add_button(new Klawisz('d'));
    klawiatura1->add_button(new Klawisz('e'));

    klawiatura1->push_button('f');
    
}