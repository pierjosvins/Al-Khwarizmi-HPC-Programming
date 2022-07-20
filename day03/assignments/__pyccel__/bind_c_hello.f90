module bind_c_hello

  use hello, only: get_num_threads
  use hello, only: hello__init

  use, intrinsic :: ISO_C_Binding, only : i64 => C_INT64_T
  implicit none

  contains

  !........................................
  function bind_c_get_num_threads(n) bind(c) result(result)

    implicit none

    integer(i64), value :: n
    integer(i64) :: result

    result = get_num_threads(n)

  end function bind_c_get_num_threads
  !........................................

  !........................................
  subroutine bind_c_hello__init() bind(c) 

    implicit none

    call hello__init()

  end subroutine bind_c_hello__init
  !........................................

end module bind_c_hello
