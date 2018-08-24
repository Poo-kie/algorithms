using System;
using Pke.Algorithms.Geometry.Planar.Models;

namespace Pke.Algorithms.Geometry.Planar
{
    public static class CoordinateArrayTransforms
    {
        public static Coordinate[] WithLowestLeftmostCoordinateAtHead(this Coordinate[] coordinates)
        {
            Coordinate llmCoordinate = coordinates[0];
            var llmIndex = 0;

            for (var i = 0; i < coordinates.Length; i++)
            {
                if ((llmCoordinate.Y.AlmostEquals(coordinates[i].Y) && llmCoordinate.X > coordinates[i].X) ||
                    (llmCoordinate.Y > coordinates[i].Y))
                {
                    llmIndex = i;
                    llmCoordinate = coordinates[i];
                }
            }

            coordinates[llmIndex] = coordinates[0];
            coordinates[0] = llmCoordinate;

            return coordinates;
        }

        // note: sorting elements in place rather than allocating another
        // array/list with LINQ using OrderBy
        public static Coordinate[] SortByAngleWithHeadAsc(this Coordinate[] coordinates)
        {
            var head = coordinates[0];

            // a vector formed by an arbitrary point
            // to the immediate left of the head
            var referenceVector = new Vector(new Coordinate(head.X - 1, head.Y), head);

            Array.Sort(coordinates, new AngleWithVectorComparer(referenceVector));

            return coordinates;
        }
    }
}
