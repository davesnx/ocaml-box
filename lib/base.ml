module String = struct
  external length : string -> int = "%string_length"

  let split_lines =
    let back_up_at_newline ~t ~pos ~eol =
      pos := !pos - if !pos > 0 && Char.equal t.[!pos - 1] '\r' then 2 else 1;
      eol := !pos + 1
    in
    fun t ->
      let n = length t in
      if n = 0
      then []
      else (
        (* Invariant: [-1 <= pos < eol]. *)
        let pos = ref (n - 1) in
        let eol = ref n in
        let ac = ref [] in
        (* We treat the end of the string specially, because if the string ends with a
          newline, we don't want an extra empty string at the end of the output. *)
        if Char.equal t.[!pos] '\n' then back_up_at_newline ~t ~pos ~eol;
        while !pos >= 0 do
          if t.[!pos] <> '\n'
          then decr pos
          else (
            (* Because [pos < eol], we know that [start <= eol]. *)
            let start = !pos + 1 in
            ac := String.sub t start (!eol - start) :: !ac;
            back_up_at_newline ~t ~pos ~eol)
        done;
        String.sub t 0 !eol :: !ac)
  ;;
end
