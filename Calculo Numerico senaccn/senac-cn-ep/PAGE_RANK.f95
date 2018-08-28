PROGRAM PAGE_RANK
    implicit none
    double precisao, dimension(4,4) :: A
    double precisao, dimension(:), allocatable :: V
!de outros para 1
    A(1,1) = 0
    A(2,1) = 0
    A(3,1) = 1
    A(4,1) = 1/2.0
!de outros para 2
    A(1,2) = 1/3.0
    A(2,2) = 0
    A(3,2) = 0
    A(4,2) = 0
!de outros para 3
    A(1,3) = 1/3.0
    A(2,3) = 1/2.0
    A(3,3) = 0
    A(4,3) = 1/2.0
!de outros para 4
    A(1,4) = 1/3.0
    A(2,4) = 1/2.0
    A(3,4) = 0
    A(4,4) = 0

    V = calcula(A)
    print *, V
    contains
    function calcula(A)
        double precisao, dimension(:, :) :: A
        real :: x, m
        integer :: n, i, j, count
        double precisao, dimension (:), allocatable :: calcula, sm
        double precisao :: antes, precisao
        m = 0.15
        antes = 1
        precisao = 0.0005
        count = 0
        n = sqrt(x)
        x = size(A)
        allocate(calcula(n))
        allocate(sm(n))

        do i = 1, n
            do j = 1, n
                a(i,j) = A(i, j) * (1 - m)
            enddo
        enddo

        do i = 1, n
            calcula(i) = 1.0/n
            sm(i) = (1.0/n) * m 
        enddo

        do while(abs(antes - calcula(1)) > precisao)
            antes = calcula(1)

            !(1-m)Ay
            calcula = MATMUL(A, calcula)

            !(1-m)Ay + sm
            do j = 1, n
                calcula(j) = calcula(j) + sm(j)
            enddo
            count = count + 1
        enddo

    end function

END PROGRAM PAGE_RANK