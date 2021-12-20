type t = {
  top: int,
  right: int,
  bottom: int,
  left: int,
};

let make = (~top=0, ~right=0, ~bottom=0, ~left=0, _) => {
  { top, right, bottom, left }
};

let empty = { top: 0, right: 0, bottom: 0, left: 0 };

let all = value => make(~top=value, ~right=value, ~bottom=value, ~left=value, ());

let top = top => make(~top, ());
let right = right => make(~right, ());
let bottom = bottom => make(~bottom, ());
let left = left => make(~left, ());

let horitzontal = value => make(~left=value, ~right=value, ());
let vertical = value => make(~top=value, ~bottom=value, ());

let topLeft = (top, left) => make(~top, ~left, ());
let topRight = (top, right) => make(~top, ~right, ());
let topBottom = (top, bottom) => make(~top, ~bottom, ());

let bottomLeft = (bottom, left) => make(~bottom, ~left, ());
let bottomRight = (bottom, right) => make(~bottom, ~right, ());
let bottomTop = (bottom, top) => make(~bottom, ~top, ());

let rightBottom = (right, bottom) => make(~right, ~bottom, ());
let rightLeft = (right, left) => make(~right, ~left, ());

let leftBottom = (left, bottom) => make(~left, ~bottom, ());
let leftTop = (left, top) => make(~left, ~top, ());
let leftRight = (left, right) => make(~left, ~right, ());
