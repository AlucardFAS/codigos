PROGRAM newton
IMPLICIT NONE

    REAL :: in, sqr, erro
    INTEGER :: count, max
    CHARACTER(len = 32) :: arg
    CALL get_command_argument(1, arg)
    READ (arg, *) in
    IF (in < 0) THEN
        PRINT *, "Input precisa ser maior que 0"
        STOP 1
    END IF

    count = 0
    max = 10000
    erro = 1E-6
    sqr = 1

    DO WHILE (ABS(sqr ** 2 - in) > erro .AND. count < max)
        sqr = ((in / sqr) + sqr) / 2
        count = count + 1
    END DO

    PRINT *, sqr

END PROGRAM Newton