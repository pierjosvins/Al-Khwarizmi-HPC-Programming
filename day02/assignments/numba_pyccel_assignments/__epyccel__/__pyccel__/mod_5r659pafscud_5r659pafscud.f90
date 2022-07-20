module mod_5r659pafscud_5r659pafscud


  use, intrinsic :: ISO_C_Binding, only : i64 => C_INT64_T , f64 => &
        C_DOUBLE
  implicit none

  contains

  !........................................
  function solve_1d_burger_pyccel(u, un, nt, nx, dt, dx, nu) result( &
        Out_0001)

    implicit none

    integer(i64) :: Out_0001
    real(f64), intent(inout) :: u(0:)
    real(f64), intent(inout) :: un(0:)
    integer(i64), value :: nt
    integer(i64), value :: nx
    real(f64), value :: dt
    real(f64), value :: dx
    real(f64), value :: nu
    integer(i64) :: n
    integer(i64) :: i

    !fill the update of u
    do n = 0_i64, nt - 1_i64, 1_i64
      do i = 0_i64, nx - 1_i64, 1_i64
        un(i) = u(i)
      end do
      do i = 1_i64, nx - 1_i64 - 1_i64, 1_i64
        u(i) = un(i) - un(i) * dt / dx * (un(i) - un(i - 1_i64)) + nu * &
              dt / dx ** 2_i64 * (un(i + 1_i64) - 2_i64 * un(i) + un(i &
              - 1_i64))
      end do
      u(0_i64) = un(0_i64) - un(0_i64) * dt / dx * (un(0_i64) - un(size( &
            un, kind=i64) - 2_i64)) + nu * dt / dx ** 2_i64 * (un(1_i64 &
            ) - 2_i64 * un(0_i64) + un(size(un, kind=i64) - 2_i64))
      u(size(u, kind=i64) - 1_i64) = u(0_i64)
    end do
    Out_0001 = 0_i64
    return

  end function solve_1d_burger_pyccel
  !........................................

end module mod_5r659pafscud_5r659pafscud
