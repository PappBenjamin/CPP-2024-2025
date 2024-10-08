#include "List.h"
#include "Stack.h"

int main()
{
   List list;

   for(int i = 0; i < 10; i++)
   {
       list.insertFirst(i);
   }

   list.remove(4,List::DeleteFlag::EQUAL);
   list.removeFirst();

   list.print();

   cout << endl;

   ///////////////////////////////////////////

   Stack stack;

   for(int i = 0; i < 10; i++)
   {
       stack.push(i);
   }


   stack.print();
}
