let columns = () => {
  switch (Sys.getenv_opt("COLUMNS")) {
  | Some(value) => int_of_string(value)
  | None => 80
  }
};
