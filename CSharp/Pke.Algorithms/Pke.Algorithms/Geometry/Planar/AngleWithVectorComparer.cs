using System;
using System.Collections.Generic;
using Pke.Algorithms.Geometry.Planar.Models;

namespace Pke.Algorithms.Geometry.Planar
{
    /// <summary>
    /// Given a vector with coordinates A and B,
    /// this compares the angles formed by AB BC and AB BD , where C
    /// and D are the vectors formed by the coordinates
    /// Bx and By (x an y are arguments to Compare)
    /// </summary>
    internal class AngleWithVectorComparer : IComparer<Coordinate>
    {
        private readonly Vector _referenceVector;

        public AngleWithVectorComparer(Vector vector)
        {
            _referenceVector = vector ?? throw new ArgumentNullException(nameof(vector));
        }

        public int Compare(Coordinate x, Coordinate y)
        {
            if (x == null) throw new ArgumentNullException(nameof(x));
            if (y == null) throw new ArgumentNullException(nameof(y));

            var v1 = new Vector(_referenceVector.B, x);
            var v2 = new Vector(_referenceVector.B, y);

            var cos1 = Cosine.FromVectors(_referenceVector, v1);
            var cos2 = Cosine.FromVectors(_referenceVector, v2);

            if (x.Equals(_referenceVector.B) || cos1.AlmostEquals(cos2)) return 0;
            if (cos1 < cos2) return -1;

            return 1;
        }
    }
}
