using System.Collections.Generic;
using System.Linq;
using Pke.Algorithms.Geometry.Planar.Models;

namespace Pke.Algorithms.Geometry.Planar.Algorithms
{
    public class GrahamScan : IFilterCoordinates<ConvexHull>
    {
        public ConvexHull Execute(IEnumerable<Coordinate> coordinates)
        {
            var arr = coordinates as Coordinate[] ?? coordinates.ToArray();
            var preparedPoints = arr.WithLowestLeftmostCoordinateAtHead()
                                    .SortByAngleWithHeadAsc();

            var convexHull = new ConvexHull();

            convexHull.AddFirst(preparedPoints[0]);
            convexHull.AddFirst(preparedPoints[1]);
            convexHull.AddFirst(preparedPoints[2]);

            for (var i = 3; i < preparedPoints.Length; i ++)
            {
                if (new CrossProduct(convexHull.First.Value, convexHull.First.Next.Value, preparedPoints[i]).ToDirection() != Direction.Left)
                    convexHull.RemoveFirst();

                convexHull.AddFirst(preparedPoints[i]);    
            }

            return convexHull;
        }
    }
}
