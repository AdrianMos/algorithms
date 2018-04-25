using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace VisitorPattern
{
    class PainterVisitor : IVisitor
    {
        public void Visit(Room room)
        {
            room.Color = "white";
        }

        public void Visit(Garage garage)
        {
            garage.Color = "blue";
            garage.DoorColor = "white";
        }
    }
}
