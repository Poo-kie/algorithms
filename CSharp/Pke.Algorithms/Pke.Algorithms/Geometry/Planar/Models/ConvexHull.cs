using System.Collections.Generic;

namespace Pke.Algorithms.Geometry.Planar.Models
{
    public class ConvexHull : PkeStack<Coordinate>
    {
        public ConvexHull()
        {
        }

        public ConvexHull(IEnumerable<Coordinate> collection) : base(collection)
        {
        }
    }
}
