#include <vector>
#include <cstdlib>
#include <ctime>
#include <iostream>

class IAlgorithm {
    public:

        virtual std::vector<int> Run(int m, int n) = 0;

};

class SelectionAlgorithm : public IAlgorithm {
    public:

    std::vector<int> Run(int m, int n) override
    {
        std::vector<int> result (m);

        std::srand(std::time(nullptr));

        bool exists = false;
        int random_variable;

        for (int i = 0; i < m; ++i)
        {
            do {
                exists = false;
                random_variable = 1 + std::rand()/((RAND_MAX + 1u)/n);

                if (i > 0)
                {
                    for (int j = 0; j < i-1; ++j)
                    {
                        if (result[j] == random_variable) 
                        {
                            exists = true;
                            break;
                        }
                    }
                }
            } while (exists);

            result[i] = random_variable;
        }

        return result;
    }
};

class RandomTest : public IAlgorithm {
    public:
        std::vector<int> Run(int m, int n) override
        {
            std::vector<int> result;
            int choose = m;
            int left = n;
            double prob = 0;
            double random_variable;
            std::srand(std::time(nullptr));
            for (int i = 0; i < n; ++i)
            {
                
                prob = double(choose)/left;
                random_variable = ((double) std::rand() / (RAND_MAX));
            
                if (random_variable < prob)
                {
                    result.push_back(i+1);
                    choose -= 1;
                }
                left -= 1;
            }
            return result;
        }
};


class Shuffle : public IAlgorithm {
    public:
        std::vector<int> Run(int m, int n) override
        {
            std::vector<int> result(m);
            std::vector<int> T(n);
            int random_variable;
            std::srand(std::time(nullptr));
            int temp;

            for (int i = 0; i<n; ++i) T[i] = i+1;
            
            for (int i = 0; i < m; ++i)
            {
                random_variable = std::rand()%n;
                temp = T[i];
                T[i] = T[random_variable];
                T[random_variable] = temp;

            }

            for (int i = 0; i<m; ++i)
            {
                result[i] = T[i];
            }
            sort(result.begin(), result.end());
            return result;
        }
};


class IFactory {
        
    public:
        IAlgorithm* algorithm;
        IFactory();
        IFactory(IAlgorithm* alg)
        {
            algorithm = alg;
        }
        virtual std::vector<int> Generate(int m, int n) = 0;
};

class Factory1 : public IFactory{
    public:
        Factory1() : IFactory(new SelectionAlgorithm())
        {

        }

        std::vector<int> Generate(int m, int n) override
        {
            return algorithm->Run(m, n);
        }

};

class Factory2 : public IFactory{
    public:
        Factory2() : IFactory(new RandomTest())
        {

        }

        std::vector<int> Generate(int m, int n) override
        {
            return algorithm->Run(m, n);
        }

};

class Factory3 : public IFactory{
    public:
        Factory3() : IFactory(new Shuffle())
        {

        }

        std::vector<int> Generate(int m, int n) override
        {
            return algorithm->Run(m, n);
        }

};

int main()
{
    int m =2;
    int n = 5;
    bool sort = true;

    IFactory* factory;

    if (!sort)
    {
        factory = new Factory1();
        std::cout<<"Factory1\n";
    }
    else{
        if (n - m > 2)
        {
            factory = new Factory3();
            std::cout<<"Factory3\n";
        }
        else{
            factory = new Factory2();
            std::cout<<"Factory2\n";
        }
    }

    std::vector<int> result = factory->Generate(m, n);

    for (int i = 0; i<result.size(); ++i) std::cout<<result[i]<<" ";
}