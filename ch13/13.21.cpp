// no, although thees classes allocate resources, but they use shared_ptr to
// manage them, so default copy-control members will free resources at
// appropriate time.