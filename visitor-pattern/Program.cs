using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace VisitorPattern
{
    class 
        Program
    {
        static void printProgramHeader()
        {
            Console.WriteLine("________________________________________________________________\n");
            Console.WriteLine("Visitor Pattern");
            Console.WriteLine("________________________________________________________________\n");

            Console.WriteLine("Two Visitors, a painter and a floor carpenter \n" +
                              "visit a Room and a Garage object:");
            Console.WriteLine("________________________________________________________________\n\n");
        }
        static void Main(string[] args)
        {
            // Two Visitors, a painter and a floor carpenter 
            // visit a Room and a Garage object.
            // The visitors have distinct behavior based on the visited object.

            // Advantages/Disadvantages:
            // + visitors can be added without updating the Room and Garage code
            // - including other visitors implies updating the code for all visitors

            printProgramHeader();

            Room room = new Room();
            Garage garage = new Garage();

            IVisitor painter = new PainterVisitor();
            IVisitor carpenter = new FloorCarpenterVisitor();

            Console.WriteLine(room.ToString());
            room.Accept(painter);
            Console.WriteLine(room.ToString());
            room.Accept(carpenter);
            Console.WriteLine(room.ToString());

            Console.WriteLine("\n________________________________\n");

            Console.WriteLine(garage.ToString());
            garage.Accept(painter);
            Console.WriteLine(garage.ToString());
            garage.Accept(carpenter);
            Console.WriteLine(garage.ToString());
            
            Console.ReadKey();
        }
    }
}
