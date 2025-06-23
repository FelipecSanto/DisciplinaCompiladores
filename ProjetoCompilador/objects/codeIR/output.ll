; ModuleID = 'parser'
source_filename = "parser"

@str_literal = global [7 x i8] c"\22%d\\n\22\00"
@str_literal.1 = global [19 x i8] c"\22i = %d, j = %d\\n\22\00"
@str_literal.2 = global [19 x i8] c"\22i = %d, x = %d\\n\22\00"
@str_literal.3 = global [19 x i8] c"\22k = %d, m = %d\\n\22\00"
@str_literal.4 = global [14 x i8] c"\22%d \C3\A9 par\\n\22\00"
@str_literal.5 = global [17 x i8] c"\22%d \C3\A9 \C3\ADmpar\\n\22\00"
@str_literal.6 = global [19 x i8] c"\22a = %d, b = %d\\n\22\00"

declare i32 @printf(ptr, ...)

declare i32 @scanf(ptr, ...)

define i32 @main() {
entry:
  %a = alloca i32, align 4
  store i32 2, ptr %a, align 4
  %b = alloca i32, align 4
  store i32 3, ptr %b, align 4
  %i = alloca i32, align 4
  store i32 0, ptr %i, align 4
  br label %for.cond

for.cond:                                         ; preds = %for.inc, %entry
  %loadtmp = load i32, ptr %i, align 4
  %cmptmp = icmp slt i32 %loadtmp, 5
  br i1 %cmptmp, label %for.body, label %for.end

for.body:                                         ; preds = %for.cond
  %loadtmp1 = load i32, ptr %a, align 4
  %loadtmp2 = load i32, ptr %b, align 4
  %addtmp = add i32 %loadtmp1, %loadtmp2
  store i32 %addtmp, ptr %b, align 4
  br label %for.inc

for.inc:                                          ; preds = %for.body
  %current_value = load i32, ptr %i, align 4
  %incremented_value = add i32 %current_value, 1
  store i32 %incremented_value, ptr %i, align 4
  br label %for.cond

for.end:                                          ; preds = %for.cond
  %c = alloca i32, align 4
  store i32 10, ptr %c, align 4
  br label %while.cond

while.cond:                                       ; preds = %while.body, %for.end
  %loadtmp3 = load i32, ptr %c, align 4
  %cmptmp4 = icmp sgt i32 %loadtmp3, 5
  br i1 %cmptmp4, label %while.body, label %while.end

while.body:                                       ; preds = %while.cond
  %loadtmp5 = load i32, ptr %c, align 4
  %subtmp = sub i32 %loadtmp5, 1
  store i32 %subtmp, ptr %c, align 4
  br label %while.cond

while.end:                                        ; preds = %while.cond
  store i32 5, ptr %c, align 4
  br label %do.body

do.body:                                          ; preds = %do.cond, %while.end
  %loadtmp6 = load i32, ptr %c, align 4
  %0 = call i32 (ptr, ...) @printf(ptr @str_literal, i32 %loadtmp6)
  %current_value7 = load i32, ptr %c, align 4
  %decremented_value = sub i32 %current_value7, 1
  store i32 %decremented_value, ptr %c, align 4
  br label %do.cond

do.cond:                                          ; preds = %do.body
  %loadtmp8 = load i32, ptr %c, align 4
  %cmptmp9 = icmp sgt i32 %loadtmp8, 0
  br i1 %cmptmp9, label %do.body, label %do.end

do.end:                                           ; preds = %do.cond
  %i14 = alloca i32, align 4
  store i32 0, ptr %i, align 4
  br label %for.cond10

for.cond10:                                       ; preds = %for.inc12, %do.end
  %loadtmp15 = load i32, ptr %i, align 4
  %cmptmp16 = icmp slt i32 %loadtmp15, 3
  br i1 %cmptmp16, label %for.body11, label %for.end13

for.body11:                                       ; preds = %for.cond10
  %j = alloca i32, align 4
  store i32 0, ptr %j, align 4
  br label %for.cond19

for.inc12:                                        ; preds = %for.end22
  %loadtmp17 = load i32, ptr %i, align 4
  %addtmp18 = add i32 %loadtmp17, 1
  store i32 %addtmp18, ptr %i, align 4
  br label %for.cond10

for.end13:                                        ; preds = %for.cond10
  %i33 = alloca i32, align 4
  store i32 0, ptr %i, align 4
  br label %for.cond29

for.cond19:                                       ; preds = %for.inc21, %for.body11
  %loadtmp23 = load i32, ptr %j, align 4
  %cmptmp24 = icmp slt i32 %loadtmp23, 2
  br i1 %cmptmp24, label %for.body20, label %for.end22

for.body20:                                       ; preds = %for.cond19
  %loadtmp27 = load i32, ptr %i, align 4
  %loadtmp28 = load i32, ptr %j, align 4
  %1 = call i32 (ptr, ...) @printf(ptr @str_literal.1, i32 %loadtmp27, i32 %loadtmp28)
  br label %for.inc21

for.inc21:                                        ; preds = %for.body20
  %loadtmp25 = load i32, ptr %j, align 4
  %addtmp26 = add i32 %loadtmp25, 1
  store i32 %addtmp26, ptr %j, align 4
  br label %for.cond19

for.end22:                                        ; preds = %for.cond19
  br label %for.inc12

for.cond29:                                       ; preds = %for.inc31, %for.end13
  %loadtmp34 = load i32, ptr %i, align 4
  %cmptmp35 = icmp slt i32 %loadtmp34, 3
  br i1 %cmptmp35, label %for.body30, label %for.end32

for.body30:                                       ; preds = %for.cond29
  %loadtmp38 = load i32, ptr %i, align 4
  %x = alloca i32, align 4
  store i32 %loadtmp38, ptr %x, align 4
  br label %while.cond39

for.inc31:                                        ; preds = %while.end41
  %loadtmp36 = load i32, ptr %i, align 4
  %addtmp37 = add i32 %loadtmp36, 1
  store i32 %addtmp37, ptr %i, align 4
  br label %for.cond29

for.end32:                                        ; preds = %for.cond29
  %k = alloca i32, align 4
  store i32 2, ptr %k, align 4
  br label %while.cond48

while.cond39:                                     ; preds = %while.body40, %for.body30
  %loadtmp42 = load i32, ptr %x, align 4
  %cmptmp43 = icmp sgt i32 %loadtmp42, 0
  br i1 %cmptmp43, label %while.body40, label %while.end41

while.body40:                                     ; preds = %while.cond39
  %loadtmp44 = load i32, ptr %i, align 4
  %loadtmp45 = load i32, ptr %x, align 4
  %2 = call i32 (ptr, ...) @printf(ptr @str_literal.2, i32 %loadtmp44, i32 %loadtmp45)
  %loadtmp46 = load i32, ptr %x, align 4
  %subtmp47 = sub i32 %loadtmp46, 1
  store i32 %subtmp47, ptr %x, align 4
  br label %while.cond39

while.end41:                                      ; preds = %while.cond39
  br label %for.inc31

while.cond48:                                     ; preds = %for.end56, %for.end32
  %loadtmp51 = load i32, ptr %k, align 4
  %cmptmp52 = icmp sgt i32 %loadtmp51, 0
  br i1 %cmptmp52, label %while.body49, label %while.end50

while.body49:                                     ; preds = %while.cond48
  %m = alloca i32, align 4
  store i32 0, ptr %m, align 4
  br label %for.cond53

while.end50:                                      ; preds = %while.cond48
  %z = alloca i32, align 4
  store i32 4, ptr %z, align 4
  br label %do.body65

for.cond53:                                       ; preds = %for.inc55, %while.body49
  %loadtmp57 = load i32, ptr %m, align 4
  %cmptmp58 = icmp slt i32 %loadtmp57, 3
  br i1 %cmptmp58, label %for.body54, label %for.end56

for.body54:                                       ; preds = %for.cond53
  %loadtmp61 = load i32, ptr %k, align 4
  %loadtmp62 = load i32, ptr %m, align 4
  %3 = call i32 (ptr, ...) @printf(ptr @str_literal.3, i32 %loadtmp61, i32 %loadtmp62)
  br label %for.inc55

for.inc55:                                        ; preds = %for.body54
  %loadtmp59 = load i32, ptr %m, align 4
  %addtmp60 = add i32 %loadtmp59, 1
  store i32 %addtmp60, ptr %m, align 4
  br label %for.cond53

for.end56:                                        ; preds = %for.cond53
  %current_value63 = load i32, ptr %k, align 4
  %decremented_value64 = sub i32 %current_value63, 1
  store i32 %decremented_value64, ptr %k, align 4
  br label %while.cond48

do.body65:                                        ; preds = %do.cond66, %while.end50
  %loadtmp68 = load i32, ptr %z, align 4
  %divtmp = sdiv i32 %loadtmp68, 2
  %cmptmp69 = icmp eq i32 %divtmp, 0
  br i1 %cmptmp69, label %if, label %next_cond

do.cond66:                                        ; preds = %endif
  %loadtmp74 = load i32, ptr %z, align 4
  %cmptmp75 = icmp sgt i32 %loadtmp74, 0
  br i1 %cmptmp75, label %do.body65, label %do.end67

do.end67:                                         ; preds = %do.cond66
  store i32 2, ptr %a, align 4
  br label %do.body76

if:                                               ; preds = %do.body65
  %loadtmp70 = load i32, ptr %z, align 4
  %4 = call i32 (ptr, ...) @printf(ptr @str_literal.4, i32 %loadtmp70)
  br label %intermediary

next_cond:                                        ; preds = %do.body65
  %loadtmp71 = load i32, ptr %z, align 4
  %5 = call i32 (ptr, ...) @printf(ptr @str_literal.5, i32 %loadtmp71)
  br label %intermediary

intermediary:                                     ; preds = %next_cond, %if
  br label %endif

endif:                                            ; preds = %intermediary
  %current_value72 = load i32, ptr %z, align 4
  %decremented_value73 = sub i32 %current_value72, 1
  store i32 %decremented_value73, ptr %z, align 4
  br label %do.cond66

do.body76:                                        ; preds = %do.cond77, %do.end67
  store i32 1, ptr %b, align 4
  br label %do.body79

do.cond77:                                        ; preds = %do.end81
  %loadtmp90 = load i32, ptr %a, align 4
  %cmptmp91 = icmp sgt i32 %loadtmp90, 0
  br i1 %cmptmp91, label %do.body76, label %do.end78

do.end78:                                         ; preds = %do.cond77
  %z92 = alloca i32, align 4
  store i32 2, ptr %z, align 4
  ret i32 0

do.body79:                                        ; preds = %do.cond80, %do.body76
  %loadtmp82 = load i32, ptr %a, align 4
  %loadtmp83 = load i32, ptr %b, align 4
  %6 = call i32 (ptr, ...) @printf(ptr @str_literal.6, i32 %loadtmp82, i32 %loadtmp83)
  %current_value84 = load i32, ptr %b, align 4
  %incremented_value85 = add i32 %current_value84, 1
  store i32 %incremented_value85, ptr %b, align 4
  br label %do.cond80

do.cond80:                                        ; preds = %do.body79
  %loadtmp86 = load i32, ptr %b, align 4
  %cmptmp87 = icmp sle i32 %loadtmp86, 2
  br i1 %cmptmp87, label %do.body79, label %do.end81

do.end81:                                         ; preds = %do.cond80
  %current_value88 = load i32, ptr %a, align 4
  %decremented_value89 = sub i32 %current_value88, 1
  store i32 %decremented_value89, ptr %a, align 4
  br label %do.cond77
}

declare void @exit(i32)

define void @_start() {
entry:
  %0 = call i32 @main()
  call void @exit(i32 0)
  unreachable
}
