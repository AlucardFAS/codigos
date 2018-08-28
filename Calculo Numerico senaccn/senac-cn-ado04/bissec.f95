PROGRAM bissec
IMPLICIT NONE

    REAL :: low, up, erro, in, root
    INTEGER :: maxIterations, count
    CHARACTER(len = 32) :: arg
    CALL get_command_argument(1, arg)
    READ (arg, *) in
    IF (in < 0) THEN
        PRINT *, "Input must be greater then 0"
        STOP 1
    END IF

    count = 0
    maxIterations = 10000
    erro = 1E-6
    low = 0
    up = in
    root = (up + low) / 2


    DO WHILE (ABS(up - root) > erro .AND. count < maxIterations)
        IF ((root ** 2) > in) THEN
            up = root
        ELSE
            lowe = root
        END IF

        root = (up + low) / 2
        count = count + 1
    END DO

    PRINT *, root
END PROGRAM bissec