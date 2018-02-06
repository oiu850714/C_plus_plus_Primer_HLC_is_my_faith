// Because it's inserter that change the container's size, not algorithm.
// The operations that change the container's size is included in the inserter's
// implementation, not algorithm, algorithm never use container's operation to
// change container's size