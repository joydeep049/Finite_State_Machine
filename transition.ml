let transition (s : state) (e:event) : state option =
    match (s,e) with
        | (Start , A ) -> Some A_Start
        | (Start , B) -> Some Middle
        | (A_Start , A) -> Some A_Start
        | (A_Start , B) -> Some A_Start
        | (Middle, A) -> Some Middle
        | (Middle, B) -> Some End
        | (End, A) -> Some Middle
        | (End, B) -> Some End