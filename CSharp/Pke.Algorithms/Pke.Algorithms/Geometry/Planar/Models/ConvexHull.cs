using System.Collections.Generic;

namespace Pke.Algorithms.Geometry.Planar.Models
{
    public class ConvexHull : LinkedList<Coordinate>
    {
        public ConvexHull()
        {
        }

        public ConvexHull(IEnumerable<Coordinate> collection) : base(collection)
        {
        }
    }
}
