using System;
using System.Collections.Generic;

namespace Pke.Algorithms.Geometry.Planar.Models
{
    public class PkeStack<T> : LinkedList<T>
    {
        public PkeStack()
        {
        }

        public PkeStack(IEnumerable<T> collection) : base(collection)
        {
        }

        public T NextToTop { get { return this.First.Next.Value; } }

        public T Top { get { return this.First.Value; } }

        public void Push(T value)
        {
            this.AddFirst(value);
        }

        public T Pop()
        {
            var tmp = this.First.Value;

            this.RemoveFirst();

            return tmp;
        }
    }
}
