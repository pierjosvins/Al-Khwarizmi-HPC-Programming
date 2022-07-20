module hello


  use, intrinsic :: ISO_C_Binding, only : b4 => C_BOOL , i64 => &
        C_INT64_T
  implicit none

  integer(i64), bind(c) :: x
  logical(b4), private :: initialised = .False._b4

  contains

  !........................................
  function get_num_threads(n) result(result)

    use omp_lib, only: omp_get_thread_num
    use omp_lib, only: omp_set_num_threads
    use omp_lib, only: omp_get_num_threads

    implicit none

    integer(i64) :: result
    integer(i64), value :: n

    call omp_set_num_threads(n)
    !$omp parallel
    print *, 'hello from thread number:' // ' ' , omp_get_thread_num()
    result = omp_get_num_threads()
    !$omp end parallel
    return

  end function get_num_threads
  !........................................

  !........................................
  subroutine hello__init() 

    implicit none

    if (.not. initialised) then
      !write your program here
      x = get_num_threads(4_i64)
      print *, x
      initialised = .True._b4
    end if

  end subroutine hello__init
  !........................................

end module hello
