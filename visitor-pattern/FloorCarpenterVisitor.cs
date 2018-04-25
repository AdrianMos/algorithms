using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace VisitorPattern
{
    class FloorCarpenterVisitor : IVisitor
    {
        public void Visit(Room room)
        {
            room.Floor = "wooden floor";
        }

        public void Visit(Garage garage)
        {
            garage.Floor = "polished concrete floor";
        }
    }
}
