module bind_c_mod_kyugbhjfgt6e_kyugbhjfgt6e

  use mod_kyugbhjfgt6e_kyugbhjfgt6e, only: factorial_py

  use, intrinsic :: ISO_C_Binding, only : i64 => C_INT64_T
  implicit none

  contains

  !........................................
  function bind_c_factorial_py(n) bind(c) result(fact)

    implicit none

    integer(i64), value :: n
    integer(i64) :: fact

    fact = factorial_py(n)

  end function bind_c_factorial_py
  !........................................

end module bind_c_mod_kyugbhjfgt6e_kyugbhjfgt6e
