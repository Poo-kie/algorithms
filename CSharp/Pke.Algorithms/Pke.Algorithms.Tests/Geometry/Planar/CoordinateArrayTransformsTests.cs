using Pke.Algorithms.Geometry.Planar;
using Pke.Algorithms.Geometry.Planar.Models;
using Xunit;

namespace Pke.Algorithms.Tests.Geometry.Planar
{
    public class CoordinateArrayTransformsTests
    {
        protected Coordinate[] Coordinates;
        protected Coordinate LowestLeftmostCoordinate;

        public CoordinateArrayTransformsTests()
        {
            LowestLeftmostCoordinate = new Coordinate(-5, 0);

            Coordinates = new[]
            {
                new Coordinate(5,0),
                new Coordinate(1,1),
                LowestLeftmostCoordinate,
                new Coordinate(-4,0),
                new Coordinate(5,5)
            };
        }

        [Fact]
        public void WithLowestLeftmostCoordinateAtHead_ShouldReturnAnArrayOfSameLength()
        {
            var transformedCoordinates = Coordinates.WithLowestLeftmostCoordinateAtHead();

            Assert.Equal(Coordinates.Length, transformedCoordinates.Length);
        }

        [Fact]
        public void WithLowestLeftmostCoordinateAtHead_ShouldReturnAnArrayWithLowestLeftmostCoordindateAtHead()
        {
            var transformedCoordinates = Coordinates.WithLowestLeftmostCoordinateAtHead();

            Assert.Equal(LowestLeftmostCoordinate, transformedCoordinates[0]);
        }

        [Fact]
        public void SortByAngleWithHeadAsc_ShouldReturnAnArrayOfSameLength()
        {
            var transformedCoordinates = Coordinates.SortByAngleWithHeadAsc();

            Assert.Equal(5, transformedCoordinates.Length);
        }

        [Fact]
        public void SortByAngleWithHeadAsc_ShouldReturnElementsSortedByAngleWithHeadAsc()
        {
            var transformedCoordinates = Coordinates
                                            .WithLowestLeftmostCoordinateAtHead()
                                            .SortByAngleWithHeadAsc();

            Assert.Equal(LowestLeftmostCoordinate.X, transformedCoordinates[0].X);
            Assert.Equal(LowestLeftmostCoordinate.Y, transformedCoordinates[0].Y);

            Assert.Equal(5, transformedCoordinates[1].X);
            Assert.Equal(5, transformedCoordinates[1].Y);

            Assert.Equal(1, transformedCoordinates[2].X);
            Assert.Equal(1, transformedCoordinates[2].Y);

            Assert.Equal(5, transformedCoordinates[3].X);
            Assert.Equal(0, transformedCoordinates[3].Y);

            Assert.Equal(-4, transformedCoordinates[4].X);
            Assert.Equal( 0, transformedCoordinates[4].Y);
        }
    }
}
