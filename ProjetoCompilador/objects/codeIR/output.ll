; ModuleID = 'parser'
source_filename = "parser"

declare i32 @printf(ptr, ...)

declare i32 @scanf(ptr, ...)

define i32 @main() {
entry:
  %a = alloca i32, align 4
  store i32 5, ptr %a, align 4
  %b = alloca double, align 8
  store double 2.500000e+00, ptr %b, align 8
  %c = alloca i32, align 4
  store i32 10, ptr %c, align 4
  %current_value = load i32, ptr %a, align 4
  %incremented_value = add i32 %current_value, 1
  store i32 %incremented_value, ptr %a, align 4
  %current_value1 = load i32, ptr %c, align 4
  %decremented_value = sub i32 %current_value1, 1
  store i32 %decremented_value, ptr %c, align 4
  %current_value2 = load i32, ptr %a, align 4
  %incremented_value3 = add i32 %current_value2, 3
  store i32 %incremented_value3, ptr %a, align 4
  %current_value4 = load i32, ptr %a, align 4
  %decremented_value5 = sub i32 %current_value4, 8
  store i32 %decremented_value5, ptr %a, align 4
  %current_value6 = load i32, ptr %a, align 4
  %multiplied_value = mul i32 %current_value6, 2
  store i32 %multiplied_value, ptr %a, align 4
  %current_value7 = load i32, ptr %a, align 4
  %divided_value = udiv i32 %current_value7, 3
  store i32 %divided_value, ptr %a, align 4
  %current_value8 = load double, ptr %b, align 8
  %incremented_value9 = fadd double %current_value8, 1.000000e+00
  store double %incremented_value9, ptr %b, align 8
  %current_value10 = load double, ptr %b, align 8
  %incremented_value11 = fadd double %current_value10, 7.530000e+00
  store double %incremented_value11, ptr %b, align 8
  %current_value12 = load double, ptr %b, align 8
  %multiplied_value13 = fmul double %current_value12, 2.000000e+00
  store double %multiplied_value13, ptr %b, align 8
  %current_value14 = load double, ptr %b, align 8
  %decremented_value15 = fsub double %current_value14, 7.500000e-01
  store double %decremented_value15, ptr %b, align 8
  %current_value16 = load double, ptr %b, align 8
  %divided_value17 = fdiv double %current_value16, 2.000000e+00
  store double %divided_value17, ptr %b, align 8
  %loadtmp = load i32, ptr %a, align 4
  %current_value18 = load i32, ptr %c, align 4
  %incremented_value19 = add i32 %current_value18, %loadtmp
  store i32 %incremented_value19, ptr %c, align 4
  %loadtmp20 = load double, ptr %b, align 8
  %current_value21 = load i32, ptr %c, align 4
  %floattoint = fptosi double %loadtmp20 to i32
  %decremented_value22 = sub i32 %current_value21, %floattoint
  store i32 %decremented_value22, ptr %c, align 4
  %current_value23 = load i32, ptr %c, align 4
  %multiplied_value24 = mul i32 %current_value23, 2
  store i32 %multiplied_value24, ptr %c, align 4
  %current_value25 = load i32, ptr %c, align 4
  %divided_value26 = udiv i32 %current_value25, 5
  store i32 %divided_value26, ptr %c, align 4
  ret i32 0
}

declare void @exit(i32)

define void @_start() {
entry:
  %0 = call i32 @main()
  call void @exit(i32 0)
  unreachable
}
