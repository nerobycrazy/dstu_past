using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace First_lesson
{
    class Program
    {
        static void Main(string[] args)
        {
            enum gradus:int{min=0,krit=72,max=100};
       
            Console.WriteLine("минимальная температура=" + gradus.min);
            Console.WriteLine("критическая температура=" + gradus.krit);
            Console.WriteLine("максимальная температура=" + gradus.max);
 

            //Console.WriteLine("Hello!");
            //Console.ReadLine();
        }
    }
}
