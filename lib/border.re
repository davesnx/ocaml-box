type symbols = {
  topLeft: string,
  top: string,
  topRight: string,
  right: string,
  bottomRight: string,
  bottom: string,
  bottomLeft: string,
  left: string,
};

let single = {
  topLeft: {|┌|},
  top: {|─|},
  topRight: {|┐|},
  right: {|│|},
  bottomRight: {|┘|},
  bottom: {|─|},
  bottomLeft: {|└|},
  left: {|│|},
};
let double = {
  topLeft: {|╔|},
  top: {|═|},
  topRight: {|╗|},
  right: {|║|},
  bottomRight: {|╝|},
  bottom: {|═|},
  bottomLeft: {|╚|},
  left: {|║|},
};
let round = {
  topLeft: {|╭|},
  top: {|─|},
  topRight: {|╮|},
  right: {|│|},
  bottomRight: {|╯|},
  bottom: {|─|},
  bottomLeft: {|╰|},
  left: {|│|},
};
let bold = {
  topLeft: {|┏|},
  top: {|━|},
  topRight: {|┓|},
  right: {|┃|},
  bottomRight: {|┛|},
  bottom: {|━|},
  bottomLeft: {|┗|},
  left: {|┃|},
};
let singleDouble = {
  topLeft: {|╓|},
  top: {|─|},
  topRight: {|╖|},
  right: {|║|},
  bottomRight: {|╜|},
  bottom: {|─|},
  bottomLeft: {|╙|},
  left: {|║|},
};
let doubleSingle = {
  topLeft: {|╒|},
  top: {|═|},
  topRight: {|╕|},
  right: {|│|},
  bottomRight: {|╛|},
  bottom: {|═|},
  bottomLeft: {|╘|},
  left: {|│|},
};
let classic = {
  topLeft: {|+|},
  top: {|-|},
  topRight: {|+|},
  right: {|||},
  bottomRight: {|+|},
  bottom: {|-|},
  bottomLeft: {|+|},
  left: {|||},
};
let arrow = {
  topLeft: {|↘|},
  top: {|↓|},
  topRight: {|↙|},
  right: {|←|},
  bottomRight: {|↖|},
  bottom: {|↑|},
  bottomLeft: {|↗|},
  left: {|→|},
};

type t =
  | Single
  | Double
  | Round
  | Bold
  | SingleDouble
  | DoubleSingle
  | Arrow
  | Classic
  | Custom(symbols);

let symbols =
  fun
  | Single => single
  | Double => double
  | Round => round
  | Bold => bold
  | SingleDouble => singleDouble
  | DoubleSingle => doubleSingle
  | Arrow => arrow
  | Classic => classic
  | Custom(symbols) => symbols;
