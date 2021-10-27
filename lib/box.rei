let render:
  (
    ~align: [ | `Left | `Center | `Right]=?,
    ~padding: int=?,
    ~margin: int=?,
    ~kind: Border.t=?,
    string
  ) => string;
