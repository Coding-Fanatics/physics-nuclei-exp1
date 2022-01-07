#include<iostream>
#include<random>
#include<ctime>

int main()
{
    double n, HalfLife, p;
    int Nuclei;
    double ParentList[21], DaughterList[21]; //i'th element of list = no. of parent/daugher nuclei a time= is
    int parent, daughter=0, t1=0;
    double d1, p1, d2, p2;

    //k=Nuclei;

    std::cout<<"enter probabilty of decay: ";
    std::cin>>p;
    std::cout<<" "<<std::endl;
    std::cout<<"enter the initial number of nuclei: ";
    std::cin>>Nuclei;
    std::cout<<" "<<std::endl;

    parent=Nuclei;

    ParentList[0]=Nuclei;
    DaughterList[0]=0;

    std::srand(time(0));

    for(int i=1; i<=20; i++) //time = i s; generate random nos for each parent nuclei every sec for i s
    {
    for(int j=0; j<Nuclei; j++) // "Nuclei" parent nuclei which need random no. generation
    {
        double n=static_cast<double>(std::rand())/ RAND_MAX; //gen random no.
        //std::cout<<n<<std::endl;
        if(n<p) //if rand no<probab, it won't decay further, and hence no longer need to be considered for random no gen
        {
            daughter++;
            parent--;
            Nuclei--; // everytime a new daughter nuclein is formed, no. nuclei to be considered for random no gen decreases by one
        }
    }
    ParentList[i]=parent;
    DaughterList[i]=daughter;
    }


    for(int i=0; i<21; i++)
    {
        std::cout<<"P"<<i<<"="<<ParentList[i]<<" "<<", "<<"d"<<i<<"="<<DaughterList[i]<<std::endl;
    }
    for(int i=0; i<21; i++)
    {
        if(ParentList[i]>DaughterList[i])
        {
            t1=i;
        }
        else
        {
            break;
        }
    }
    double t=t1;
    double fraction;
    d1=DaughterList[t1];
    d2=DaughterList[t1+1];
    p1=ParentList[t1];
    p2=ParentList[t1+1];
    fraction=((d1-p1)/(p2-p1-d2+d1));
    HalfLife= t + fraction;
    std::cout<<"Half life= "<<HalfLife<<"s"<<std::endl;
}