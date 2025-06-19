; ModuleID = 'parser'
source_filename = "parser"

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

for.cond:                                         ; preds = %for.body, %entry
  %loadtmp = load i32, ptr %i, align 4
  %cmptmp = icmp slt i32 %loadtmp, 5
  %loadtmp1 = load i32, ptr %i, align 4
  %addtmp = add i32 %loadtmp1, 1
  store i32 %addtmp, ptr %i, align 4
  br i1 %cmptmp, label %for.body, label %for.end

for.body:                                         ; preds = %for.cond
  %loadtmp2 = load i32, ptr %a, align 4
  %loadtmp3 = load i32, ptr %b, align 4
  %addtmp4 = add i32 %loadtmp2, %loadtmp3
  store i32 %addtmp4, ptr %b, align 4
  br label %for.cond

for.end:                                          ; preds = %for.cond
  %c = alloca i32, align 4
  store i32 10, ptr %c, align 4
  br label %while.cond

while.cond:                                       ; preds = %while.body, %for.end
  %loadtmp5 = load i32, ptr %c, align 4
  %cmptmp6 = icmp sgt i32 %loadtmp5, 5
  br i1 %cmptmp6, label %while.body, label %while.end

while.body:                                       ; preds = %while.cond
  %loadtmp7 = load i32, ptr %c, align 4
  %subtmp = sub i32 %loadtmp7, 1
  store i32 %subtmp, ptr %c, align 4
  br label %while.cond

while.end:                                        ; preds = %while.cond
  %z = alloca i32, align 4
  store i32 2, ptr %z, align 4
  ret i32 0
}
