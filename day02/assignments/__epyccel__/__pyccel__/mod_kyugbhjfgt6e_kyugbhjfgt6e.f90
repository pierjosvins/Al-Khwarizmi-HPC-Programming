module mod_kyugbhjfgt6e_kyugbhjfgt6e


  use, intrinsic :: ISO_C_Binding, only : i64 => C_INT64_T
  implicit none

  contains

  !........................................
  function factorial_py(n) result(fact)

    implicit none

    integer(i64) :: fact
    integer(i64), value :: n
    integer(i64) :: i

    fact = 1_i64
    do i = 2_i64, n + 1_i64 - 1_i64, 1_i64
      fact = fact * i
    end do
    return

  end function factorial_py
  !........................................

end module mod_kyugbhjfgt6e_kyugbhjfgt6e
