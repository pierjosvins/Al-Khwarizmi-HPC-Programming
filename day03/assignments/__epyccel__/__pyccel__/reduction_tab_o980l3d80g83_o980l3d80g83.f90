module reduction_tab_o980l3d80g83_o980l3d80g83


  use, intrinsic :: ISO_C_Binding, only : f64 => C_DOUBLE , i64 => &
        C_INT64_T
  implicit none

  contains

  !........................................
  function threads_num() result(Out_0001)

    use omp_lib, only: omp_get_num_threads

    implicit none

    integer(i64) :: Out_0001

    !complete this function for getting threads num
    Out_0001 = omp_get_num_threads()
    return

  end function threads_num
  !........................................

  !........................................
  subroutine initialize_table(tab, nmolec, n, nmol) 

    implicit none

    real(f64), intent(inout) :: tab(0:,0:,0:)
    integer(i64), value :: nmolec
    integer(i64), value :: n
    integer(i64), value :: nmol
    integer(i64) :: k
    integer(i64) :: j
    integer(i64) :: i

    !Initialisation du tableau
    !First-touch pour garantir un fonctionnement optimal sur les systemes NUMA
    !$omp parallel
    !$omp do collapse(3)
    do k = 0_i64, nmolec - 1_i64, 1_i64
      do j = 0_i64, n - 1_i64, 1_i64
        do i = 0_i64, nmol - 1_i64, 1_i64
          tab(k, j, i) = i + j + k
        end do
      end do
    end do
    !$omp end do
    !$omp end parallel

  end subroutine initialize_table
  !........................................

  !........................................
  subroutine reduction(tab, tab1, tab2, nmolec, nmol, n) 

    implicit none

    real(f64), intent(in) :: tab(0:,0:,0:)
    real(f64), intent(inout) :: tab1(0:)
    real(f64), intent(inout) :: tab2(0:)
    integer(i64), value :: nmolec
    integer(i64), value :: nmol
    integer(i64), value :: n
    integer(i64) :: k
    integer(i64) :: j
    integer(i64) :: i

    !$omp parallel
    !$omp do reduction(+: tab2) reduction(+: tab1)
    do k = 0_i64, nmolec - 1_i64, 1_i64
      tab1(:nmol - 1_i64) = 0_i64
      do j = 0_i64, n - 1_i64, 1_i64
        do i = 0_i64, nmol - 1_i64, 1_i64
          tab1(i) = tab1(i) + tab(k, j, i)
        end do
      end do
      tab2(:nmol - 1_i64) = tab2(:nmol - 1_i64) + 2_i64 * tab1(:nmol - &
            1_i64)
    end do
    !$omp end do
    !$omp end parallel

  end subroutine reduction
  !........................................

end module reduction_tab_o980l3d80g83_o980l3d80g83
