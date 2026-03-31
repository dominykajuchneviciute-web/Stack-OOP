#include "stack.h"
#include <iostream>

int main()
{
    try
    {
        MySpace::Stack s, s1;
        s1.add(10);
        s1+=26;
        s.add(10);
        s+=20;
        s.add(30);
        std::cout<<"First stack has 3 elements, second has 2"<<std::endl;
        if(s>s1)
            std::cout<<"First stack has more elements."<<std::endl;
        if(s<s1)
            std::cout<<"Second stack has more elements."<<std::endl;
        if(s>=s1)
            std::cout<<"First stack has more or equal number of elements to second stack."<<std::endl;
        if(s<=s1)
            std::cout<<"Second stack has more or equal number of elements to first stack."<<std::endl;
        if(s==s1)
            std::cout<<"First and second stack are equal by their size."<<std::endl;
        if(s!=s1)
            std::cout<<"First and second stack are not equal by their size."<<std::endl;
        std::cout << "Stack contents: " << s.toString() << std::endl;
        s.edit(20, 25);
        std::cout << "After editing 20 to 25: " << s.toString() << std::endl;
        s*=2;
        std::cout << "After editing multiplying by 2: " << s.toString() << std::endl;
        std::cout << "Top value: " << s.view() << std::endl;
        std::cout << "The value 50 is in " << s[50] <<" place."<< std::endl;
        s.del();
        std::cout << "Stack contents after removal: " << s.toString() << std::endl;
        s-=50;
        std::cout << "Stack contents after removal: " << s.toString() << std::endl;
        MySpace::Stack s2(s);
        std::cout << "Same stack contents(copy constructor):" << s2.toString() << s.toString() << std::endl;
        s2+=44;
        std::cout << "Stack contents after adding: " << s2.toString() << std::endl;
        s2=s;
        std::cout << "Stack contents after an assignment: " << s2.toString() << s.toString() << std::endl;
        !s;
        std::cout << "Stack contents after removal: " << s.toString() << std::endl;
    }
    catch(...)
    {

    }
    return 0;
}
