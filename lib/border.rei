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

let symbols: t => symbols;
