using System;

namespace Pke.Algorithms
{
    public static class DoubleExtensions
    {
        public const double TOLERANCE = .0000001;

        public static bool AlmostEquals(this double lValue, double rValue)
        {
            return Math.Abs(lValue - rValue) < TOLERANCE;
        }
    }
}
