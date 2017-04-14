using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Microsoft.SmallBasic.Library;

namespace TurtleTraning
{
    class Program
    {
        static void Mur()
        {
            Turtle.Turn(-90);
            Turtle.PenUp();
            Turtle.Move(200);
            Turtle.PenDown();
            Turtle.Turn(90);
            // M
            Turtle.Move(100);
            Turtle.Turn(120);
            Turtle.Move(50);
            Turtle.Turn(-60);
            Turtle.Move(50);
            Turtle.Turn(120);
            Turtle.Move(100);
            //
            Turtle.Turn(-90);
            Turtle.PenUp();
            Turtle.Move(20);
            Turtle.PenDown();
            //
            //У
            Turtle.Move(20);
            Turtle.Turn(-60);
            Turtle.Move(120);
            Turtle.Turn(180);
            Turtle.Move(60);
            Turtle.Turn(120);
            Turtle.Move(60);
            //
            Turtle.Turn(-150);
            Turtle.PenUp();
            Turtle.Move(104);
            Turtle.Turn(-90);
            Turtle.Move(80);
            Turtle.Turn(-90);
            Turtle.PenDown();
            //
            Turtle.Move(100);
            Turtle.Turn(90);
            int i = 0;
            while (i < 17)
            {
                Turtle.Turn(10);
                Turtle.Move(6);
                i++;
            }
            Turtle.Turn(-90);
            Turtle.PenUp();
            Turtle.Move(100);
        }
        static void Main(string[] args)
        {
            Turtle.Speed = 8;
            GraphicsWindow.KeyDown += GraphicsWindow_KeyDown;
            Turtle.PenUp();
            GraphicsWindow.BrushColor = "Red";
            var eda = Shapes.AddEllipse(10, 10);
            int edaX = 200;
            int edaY = 200;

            Shapes.Move(eda, edaX, edaY);
            Random rand = new Random();
            while (true)
            {
                Turtle.Move(10);
                if (Turtle.X >= edaX && Turtle.X <= edaX + 10 && Turtle.Y >= edaY && Turtle.Y <= edaY+10)
                {
                    edaX = rand.Next(0, GraphicsWindow.Width);
                    edaY = rand.Next(0, GraphicsWindow.Height);
                    Shapes.Move(eda, edaX, edaY);
                }
                
            }
        }
        private static void GraphicsWindow_KeyDown()
        {
            if (GraphicsWindow.LastKey == "Up")
            {
                Turtle.Angle = 0;
            }
            else if (GraphicsWindow.LastKey == "Right")
            {
                Turtle.Angle = 90;
            }
            else if (GraphicsWindow.LastKey == "Down")
            {
                Turtle.Angle = 180;
            }
            else if (GraphicsWindow.LastKey == "Left")
            {
                Turtle.Angle = 270;
            }
        }
    }
}
