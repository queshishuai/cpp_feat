#include <iostream>

#define COUT(o,mem) std::cout << #mem":" << o.mem << std::endl;


#define FUNC1(o,mem) COUT(o,mem) 
#define FUNC2(o,v1,v2) FUNC1(o,v1) FUNC1(o,v2)
#define FUNC3(o,v1,v2,v3) FUNC2(o,v1,v2) FUNC1(o,v3)
#define FUNC4(o,v1,v2,v3,v4) FUNC3(o,v1,v2,v3) FUNC1(o,v4)

#define GET(_1,_2,_3,_4,_5,NAME,...) NAME  

#define PASTE(...) GET(__VA_ARGS__,FUNC4,FUNC3,FUNC2,FUNC1,PLACEHOLDER) (__VA_ARGS__)

#define REG(struct_name,...)  \
std::ostream& operator<<(::std::ostream &os,struct_name &m) \
{ \
  PASTE(m,__VA_ARGS__) \
  return os; \
} 

typedef struct
{
    /* data */
    int a;
    int b;
}mac;

REG(mac,a,b);

int main()
{
  mac mc;
  std::cout << mc;
  return 0;
}
