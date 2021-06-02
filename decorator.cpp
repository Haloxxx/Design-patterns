#include <iostream>
#include <vector>

class Klawisz {
    public:
        char key;
        std::string message;

        Klawisz(char button){
            key = button;
        }

        virtual void monitor(char key_pressed) { std::cout<<"test\n";}
};


class StandardKlawisz : public Klawisz {
    protected:
        Klawisz* decorated_klawisz;
    public:

        StandardKlawisz(Klawisz* klawisz) : Klawisz(klawisz->key){
            message = "Wciśnięto klawisz ";
            decorated_klawisz = klawisz;
        }

        void monitor(char key_pressed) override{
            
            if (key_pressed == key){
                std::cout<<message<<decorated_klawisz->key<<'\n';
            }
        }
};


class Exclamation : public Klawisz {
    protected:
        Klawisz* decorated_klawisz;
    public:

        Exclamation(Klawisz* klawisz) : Klawisz(klawisz->key){
            decorated_klawisz = klawisz;
            message = decorated_klawisz->message;
        }

        void monitor (char key_pressed) override{
            
            if (key_pressed == key){
                std::cout<<message<<decorated_klawisz->key<<"!\n";
            }
            
        }
};

class Question : public Klawisz {
    protected:
        Klawisz* decorated_klawisz;
    public:

        Question(Klawisz* klawisz) : Klawisz(klawisz->key){
            decorated_klawisz = klawisz;
            message = decorated_klawisz->message;
        }

        void monitor(char key_pressed) override{
            
            if (key_pressed == key){
                std::cout<<message<<decorated_klawisz->key<<"?\n";
            }
            
        }
};

class Klawiatura {
    private:
        Klawiatura(){};
        static Klawiatura* instance;
        char* key_pressed;
        std::vector<Klawisz*> klawisze;

    public:

        Klawiatura(Klawiatura &other) = delete;
    
        void operator=(const Klawiatura &) = delete;

        static Klawiatura *get_instance(); 

        void add_button(Klawisz* button){
            klawisze.push_back(button);
        }

        void push_button(char button)
        {
            for (int i = 0; i < klawisze.size(); ++i)
            {
                if (klawisze[i]->key == button)
                {
                    klawisze[i]->monitor(button);
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

    klawiatura1->add_button(new StandardKlawisz(new Klawisz('a')));
    klawiatura1->add_button(new StandardKlawisz(new Klawisz('b')));
    klawiatura1->add_button(new StandardKlawisz(new Klawisz('c')));
    klawiatura1->add_button(new Exclamation(new StandardKlawisz(new Klawisz('d'))));
    klawiatura1->add_button(new Question(new StandardKlawisz(new Klawisz('e'))));


    klawiatura1->push_button('a');
    klawiatura1->push_button('d');
    klawiatura1->push_button('e');
    
}