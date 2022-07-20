module bind_c_reduction_tab_yh3w7i615qh3_yh3w7i615qh3

  use reduction_tab_yh3w7i615qh3_yh3w7i615qh3, only: &
        initialize_table_openmp
  use reduction_tab_yh3w7i615qh3_yh3w7i615qh3, only: reduction
  use reduction_tab_yh3w7i615qh3_yh3w7i615qh3, only: initialize_table
  use reduction_tab_yh3w7i615qh3_yh3w7i615qh3, only: reduction_openmp
  use reduction_tab_yh3w7i615qh3_yh3w7i615qh3, only: threads_num

  use, intrinsic :: ISO_C_Binding, only : f64 => C_DOUBLE , i64 => &
        C_INT64_T
  implicit none

  contains

  !........................................
  function bind_c_threads_num() bind(c) result(Out_0001)

    implicit none

    integer(i64) :: Out_0001

    Out_0001 = threads_num()

  end function bind_c_threads_num
  !........................................

  !........................................
  subroutine bind_c_initialize_table(n0_tab, n1_tab, n2_tab, tab, nmolec &
        , n, nmol) bind(c)

    implicit none

    integer(i64), value :: n0_tab
    integer(i64), value :: n1_tab
    integer(i64), value :: n2_tab
    real(f64), intent(inout) :: tab(0:n2_tab - 1_i64,0:n1_tab - 1_i64,0: &
          n0_tab - 1_i64)
    integer(i64), value :: nmolec
    integer(i64), value :: n
    integer(i64), value :: nmol

    call initialize_table(tab, nmolec, n, nmol)

  end subroutine bind_c_initialize_table
  !........................................

  !........................................
  subroutine bind_c_initialize_table_openmp(n0_tab, n1_tab, n2_tab, tab, &
        nmolec, n, nmol) bind(c)

    implicit none

    integer(i64), value :: n0_tab
    integer(i64), value :: n1_tab
    integer(i64), value :: n2_tab
    real(f64), intent(inout) :: tab(0:n2_tab - 1_i64,0:n1_tab - 1_i64,0: &
          n0_tab - 1_i64)
    integer(i64), value :: nmolec
    integer(i64), value :: n
    integer(i64), value :: nmol

    call initialize_table_openmp(tab, nmolec, n, nmol)

  end subroutine bind_c_initialize_table_openmp
  !........................................

  !........................................
  subroutine bind_c_reduction(n0_tab, n1_tab, n2_tab, tab, n0_tab1, tab1 &
        , n0_tab2, tab2, nmolec, nmol, n) bind(c)

    implicit none

    integer(i64), value :: n0_tab
    integer(i64), value :: n1_tab
    integer(i64), value :: n2_tab
    real(f64), intent(in) :: tab(0:n2_tab - 1_i64,0:n1_tab - 1_i64,0: &
          n0_tab - 1_i64)
    integer(i64), value :: n0_tab1
    real(f64), intent(inout) :: tab1(0:n0_tab1 - 1_i64)
    integer(i64), value :: n0_tab2
    real(f64), intent(inout) :: tab2(0:n0_tab2 - 1_i64)
    integer(i64), value :: nmolec
    integer(i64), value :: nmol
    integer(i64), value :: n

    call reduction(tab, tab1, tab2, nmolec, nmol, n)

  end subroutine bind_c_reduction
  !........................................

  !........................................
  subroutine bind_c_reduction_openmp(n0_tab, n1_tab, n2_tab, tab, &
        n0_tab1, tab1, n0_tab2, tab2, nmolec, nmol, n) bind(c)

    implicit none

    integer(i64), value :: n0_tab
    integer(i64), value :: n1_tab
    integer(i64), value :: n2_tab
    real(f64), intent(in) :: tab(0:n2_tab - 1_i64,0:n1_tab - 1_i64,0: &
          n0_tab - 1_i64)
    integer(i64), value :: n0_tab1
    real(f64), intent(inout) :: tab1(0:n0_tab1 - 1_i64)
    integer(i64), value :: n0_tab2
    real(f64), intent(inout) :: tab2(0:n0_tab2 - 1_i64)
    integer(i64), value :: nmolec
    integer(i64), value :: nmol
    integer(i64), value :: n

    call reduction_openmp(tab, tab1, tab2, nmolec, nmol, n)

  end subroutine bind_c_reduction_openmp
  !........................................

end module bind_c_reduction_tab_yh3w7i615qh3_yh3w7i615qh3
