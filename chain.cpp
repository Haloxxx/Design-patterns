#include <iostream>
#include <vector>
#include <memory>

int max(int a, int b)
{
    if (a > b){
        return a;
    }
    else {
        return b;
    }
}

class IAlgorithm {
    public:

        virtual std::shared_ptr<IAlgorithm> SetNext(std::shared_ptr<IAlgorithm> handler) = 0;
        virtual int Handle(std::vector<int> request) = 0;
};

class AbstractAlgorithm : public IAlgorithm {
    private:
        std::shared_ptr<IAlgorithm> nextAlgorithm;
    public:
        int Handle(std::vector<int> request)
        {
            if (nextAlgorithm)
            {
                return nextAlgorithm->Handle(request);
            }
            else
            {
                return 0;
            }
        }
        std::shared_ptr<IAlgorithm> SetNext(std::shared_ptr<IAlgorithm> handler){
            nextAlgorithm = handler;
            return nextAlgorithm;
        };
};

class QuadraticAlgorithm: public AbstractAlgorithm {
    public:
        int Handle(std::vector<int> request) override {
            bool moveToNext = false;
            std::vector<int> x = request;
            int maxsofar = 0;
            int n = x.size();

            for (int i = 0; i < n; ++i){
                int sum = 0;
                for (int j = i; j < n; ++j)
                {
                    sum += x[j];
                    maxsofar = max(maxsofar, sum);
                }

                if (i > 5)
                {
                    moveToNext = true;
                    return AbstractAlgorithm::Handle(request);
                    break;
                    break;
                }
            }

            if (!moveToNext){
                return maxsofar;
            }
            
        }
};

class LinearAlgorithm: public AbstractAlgorithm {
    public:
        int Handle(std::vector<int> request) override {
            std::vector<int> x = request;
            int maxsofar = 0;
            int maxhere = 0;
            int n = x.size();

            for (int i = 0; i < n; ++i){
                maxhere = max(maxhere + x[i], 0);
                maxsofar = max(maxsofar, maxhere);
            }

            return maxsofar;
        }
};


int main(){
    std::vector<int> x {31, -41, 59, 26, -53, 58, 97, -93, -23, 84};

    std::shared_ptr<QuadraticAlgorithm> first = std::shared_ptr<QuadraticAlgorithm>(new QuadraticAlgorithm());
    std::shared_ptr<LinearAlgorithm> second = std::shared_ptr<LinearAlgorithm>(new LinearAlgorithm());

    first->SetNext(second);

    std::cout<<(first->Handle(x));
}