type t = {
  top: int,
  right: int,
  bottom: int,
  left: int,
};

let make: (~top: int=?, ~right: int=?, ~bottom: int=?, ~left: int=?, unit) => t;

let empty: t;

let all: int => t;

let top: int => t;
let right: int => t;
let bottom: int => t;
let left: int => t;

let horitzontal: int => t;
let vertical: int => t;

let topLeft: (int, int) => t;
let topRight: (int, int) => t;
let topBottom: (int, int) => t;

let bottomLeft: (int, int) => t;
let bottomRight: (int, int) => t;
let bottomTop: (int, int) => t;

let rightBottom: (int, int) => t;
let rightLeft: (int, int) => t;

let leftBottom: (int, int) => t;
let leftTop: (int, int) => t;
let leftRight: (int, int) => t;
