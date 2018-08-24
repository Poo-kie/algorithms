using System.Collections.Generic;
using Pke.Algorithms.Geometry.Planar.Models;

namespace Pke.Algorithms.Geometry.Planar.Algorithms
{
    public interface IFilterCoordinates<out TReturn>
        where TReturn : IEnumerable<Coordinate>
    {
        TReturn Execute(IEnumerable<Coordinate> coordinates);
    }


}
