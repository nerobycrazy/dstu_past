using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CinemaAdviser
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Привет, это суперпрограмма для выбора фильмов:");
            Console.WriteLine("Выберите жанр: комедия, драма, фантастика, эротика, триллер, боевик");
            String genre = Console.ReadLine();
            if (genre == "комедия")
            {
                Console.WriteLine("Список комедий:");
                Console.WriteLine("*1+1");
                Console.WriteLine("*Трудный ребенок");
                Console.WriteLine("*Каникулы какие-то");
            }
            else if (genre == "драма")
            {
                Console.WriteLine("Список драм:");
                Console.WriteLine("*Титаник");
                Console.WriteLine("*Если я останусь");
                Console.WriteLine("*Бумажные города");
            }
            else if(genre == "фантастика")
            {
                Console.WriteLine("Список фантастики:");
                Console.WriteLine("*Мстители");
                Console.WriteLine("*Первый мститель");
                Console.WriteLine("*Халк");     
            }
            else if (genre == "триллер")
            {
                Console.WriteLine("Список триллеров:");
                Console.WriteLine("*Триллер1");
                Console.WriteLine("*Триллер2");
                Console.WriteLine("*Триллер3");
            }
            else if (genre == "боевик")
            {
                Console.WriteLine("Список боевиков:");
                Console.WriteLine("*Боевик1");
                Console.WriteLine("*Боевик2");
                Console.WriteLine("*Боевик3");
            }
            else if (genre == "эротика")
            {
                Console.WriteLine("Сколько Вам лет?: ");
                String yearString = Console.ReadLine();
                int years = Int32.Parse(yearString);
                String g = " год";
                String go = " года";
                String god = " лет";
                int t_g = 18 - years;

                if (years < 18)
                {
                    Console.WriteLine("Не дорос ещё до такого жанра.");
                    if (t_g == 1)
                    {
                        Console.WriteLine("Приходи через " + t_g + g);
                    }
                    else if ((t_g > 1) && (t_g <= 4))
                    {
                        Console.WriteLine("Приходи через " + t_g + go);
                    }
                    else
                    {
                        Console.WriteLine("Приходи через " + t_g + god);
                    }
                }
                else
                {
                    Console.WriteLine("ЭРОТИКА:");
                    Console.WriteLine("*Эротика1");
                    Console.WriteLine("*Эротика2");
                    Console.WriteLine("*Эротика3");
                }
            }
            else
            {
                Console.WriteLine("Такого жанра нет");

            }
            Console.ReadLine();
        }
    }
}
