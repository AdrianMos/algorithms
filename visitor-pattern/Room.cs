using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace VisitorPattern
{
    class Room : IVisitable       
    {
        public int SizeInMeters { get; set; }
        public string Color { get; set; }
        public string Floor { get; set; }

        public Room()
        {
            Floor = "no floor yet";
            Color = "unpainted";
            SizeInMeters = 10;
        }

        public void Accept(IVisitor visitor)
        {
            Console.WriteLine("\nVISITOR in Room");
            visitor.Visit(this);
        }

        public override string ToString()
        {
            return "The room is " + Color + " with " + Floor +
                ", size " + SizeInMeters + " sq.m" ;
        }   
    }
}
