using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace VisitorPattern
{
    class Garage : IVisitable
    {
        public string Color { get; set; }
        public string DoorColor { get; set; }
        public string Floor { get; set; }

        public Garage()
        {
            Floor = "concrete floor";
            Color = "unpainted";
            DoorColor = "rusted steel";
        }

        public void Accept(IVisitor visitor)
        {
            Console.WriteLine("\nVISITOR in Garage");
            visitor.Visit(this);
        }

        public override string ToString()
        {
            return "The garage is " + Color + ", door color " + DoorColor +
                ", " + Floor;
        }
    }
}
