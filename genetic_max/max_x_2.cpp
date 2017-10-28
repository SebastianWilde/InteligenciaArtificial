#include<bits/stdc++.h>
using namespace std;
template<typename T> void print_queue(T& q) {
    while(!q.empty()) {
        std::cout << q.top() << " ";
        q.pop();
    }
    std::cout << '\n';
}
const int LEN_CROMOSOME=5;
struct Less
{
    bool operator()( pair<int,float>&  lhs,  pair<int,float>& rhs)
    {
        return lhs.second < rhs.second;
    }
};
class Genetic_max
{
public:
    int x;
    //priority_queue<pair<int,float>,Less> prioridad;
    std::priority_queue<pair<int,float>,vector<pair<int,float>>, Less> prioridad;
    int _len;
    typedef pair<bitset<LEN_CROMOSOME>,int> cromosoma_cost;

    int n;
    vector<cromosoma_cost> sample;
    vector<cromosoma_cost> populate_select;
        ofstream myfile;


    Genetic_max(int nn)
    {
        n=nn;
   myfile.open ("genetic.txt");

    }
    int rand_num(int a,int b)
    {
        return a+(std::rand()%(b-a+1));
    }
    int f(int x)
    {
        return x*x;
    }
    void print_populate()
    {

        float sum=0;
        for(int i=0; i<sample.size(); i++)
        {
            cout<<sample[i].first<<" costo "<<sample[i].second<<endl;
            int val = (int ) (sample[i].first.to_ulong()  );
            sum+=val;
        }
        myfile<<sum/sample.size()<<endl;

    }
    int sum_cost()
    {
        int s;
        for(int i=0; i<sample.size(); i++)
        {
            int cost= (int ) sample[i].second  ;
            cout<<"cost sumatoria "<<sample[i].second<<" "<<cost<<endl;
            s+=cost;//sample[i].second;
        }
        return s;
    }
    void populate()
    {
        //sample.clear();
        for(int i=sample.size(); i<n; i++)
        {
            cout<<"agrego"<<endl;
            string temp="";//= (bitset<4>(1 )).to_string<char,string::traits_type,string::allocator_type>();
            bitset<LEN_CROMOSOME> bit(rand_num(0,31));
            temp=bit.to_string<char,string::traits_type,string::allocator_type>();

            //temp+= (bitset<4>(10)).to_string<char,string::traits_type,string::allocator_type>();
            int val = (int ) ( bitset<LEN_CROMOSOME>(temp).to_ulong()  );
            sample.push_back(cromosoma_cost(temp,val));
        }


    }
    void fitness()
    {
        for(int i=0; i<sample.size(); i++)
        {
            int cost= (int ) sample[i].first.to_ulong()  ;

            sample[i].second= f(cost);
        }
    }
    void rank()
    {
        populate_select.clear();
        int sum= sum_cost();

        cout<<"sumaa "<<sum<<endl;
        float max=0;
        for(int i=0; i<sample.size(); i++)
        {
            cout<<"f(x) "<<sample[i].second<<endl;
            float prop =( (float)sample[i].second)/sum;
            cout<<"prob seleccion "<<prop<<endl;
            prioridad.push(pair<int,float>(i,prop));
        }
        sample.clear();
        sample.push_back(sample[prioridad.top().first]);
        prioridad.pop();
        sample.push_back(sample[prioridad.top().first]);


    }
    void crossover_mutate_add()
    {



        string t= sample[0].first.to_string<char,string::traits_type,string::allocator_type>();
        string t2= sample[1].first.to_string<char,string::traits_type,string::allocator_type>();

        swap_ranges(t.begin()+1,t.end()-1,t2.begin()+1);
        populate_select.push_back(cromosoma_cost(bitset<LEN_CROMOSOME> (t),0));
        populate_select.push_back(cromosoma_cost(bitset<LEN_CROMOSOME>(t2),0));

        for(int i=0; i<populate_select.size(); i++)
        {
            cout<<"hijos son: "<<populate_select[i].first<<endl
                ;
        }
        mutate();
        for(int i=0; i<2; i++)
        {
            sample.push_back(populate_select[i]);
        }
        cout<<"despues de seleccion y cruzamiento "<<endl;
        print_populate();
        cout<<"---------"<<endl;
    }
    void mutate()
    {
        for(int i=0; i<2; i++)
        {
            populate_select[i].first.flip(rand_num(0,4));

            populate_select[i].first.flip(rand_num(0,4));

        }
    }

};
int main()
{
    srand(time(0));
    Genetic_max g(4);

    for(int i=0; i<100; i++)
    {
        g.populate();
        g.fitness();
        g.rank();
        g.crossover_mutate_add();
        cout<<"===========generacion "<<i<<" ============="<<endl;
        g.fitness();
        g.print_populate();
        cout<<"========================="<<endl;
    }

}
