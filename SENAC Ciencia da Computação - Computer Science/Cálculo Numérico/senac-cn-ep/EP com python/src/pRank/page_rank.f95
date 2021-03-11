program PAGE_RANK
implicit none

integer :: i, j, k
integer :: sinal = 1
real :: sum
real :: norm
real :: m = 0.15
real :: epsilon = 0.00005
integer :: nohsTam = 0
real, dimension (:,:), allocatable :: matriz
real, dimension (:), allocatable :: vec1, vec2
character(len=10) :: token

call getarg(sinal, token)
read (token, *) nohsTam
sinal = sinal + 1

allocate( matriz(nohsTam, nohsTam) )
allocate( vec1(nohsTam ))
allocate( vec2(nohsTam ))

do i = 1, nohsTam
    do j = 1, nohsTam
        call getarg(sinal, token)
        read (token, *) matriz(i, j)
        sinal = sinal + 1
    end do
end do

do i = 1, nohsTam
    do j = 1, nohsTam
        matriz(i, j) = (1-m) * matriz(i, j) + (m / nohsTam)
    end do
end do

do i = 1, nohsTam
    vec1(i) = 1.0 / nohsTam
    vec2(i) = 0.0           
end do

k = 1
do while (k == 1)
    do i = 1, nohsTam
        vec2(i) = vec1(i)
    end do
    do i = 1, nohsTam
        sum = 0.0
        do j = 1, nohsTam
            sum = sum + matriz(i, j) * vec2(j)
        end do
        vec1(i) = sum
    end do
    norm = 0.0
    do i = 1, nohsTam
        norm = norm + (vec1(i) - vec2(i)) * (vec1(i) - vec2(i))
    end do
    norm = sqrt(norm)
    if (norm < epsilon) then
        k = 0
    end if
end do

do i = 1, nohsTam
    print *, vec1(i)
end do

end program PAGE_RANK