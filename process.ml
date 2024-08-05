let rec process (s:state) lst : state option =
    match lst with
        | [] -> Some s
        | hd :: tl -> match char_to_event hd with
                    | Some event -> (match transition s event with
                                    | Some new_state -> process new_state tl
                                    | None ->None)
                    |  None -> None