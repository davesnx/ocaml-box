let render:
  (
    ~align: [ `Left | `Center | `Right]=?,
    ~float: [ `Left | `Center | `Right]=?,
    ~padding: int=?,
    ~margin: int=?,
    ~kind: Border.t=?,
    string
  ) => string;
