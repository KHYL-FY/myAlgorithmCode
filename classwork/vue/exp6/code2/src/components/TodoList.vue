
<template>
    <ul class="list-group">
    <li class="list-group-item d-flex justify-content-between align-items-center" v-for="item in list" :key="item.id">
    
    <div class="custom-control custom-checkbox">
        <!-- 复选框 -->
        <input type="checkbox" class="custom-control-input" :id="item.id" v-model="item.done"/>
        <!-- 注意：App 父组件传递给 list 是“引用类型”的数据， -->
        <!-- 这里 v-model 双向绑定的结果是：用户的操作修改的是 App 组件中数
        据的状态 -->

        <label class="custom-control-label" :for="item.id" :class="item.done ?'delete' :''">{{item.task }}
        </label>
    </div>
        <!-- badge 效果 -->
        <span class="badge badge-success badge-pill" v-if="item.done">完成</span>
        <span class="badge badge-warning badge-pill" v-else>未完成</span>
    </li>
    </ul>
 
</template>

<script setup>
const props=defineProps({
  // 表格的数据源
  list: {         //声明自定义属性
      type: Array,
      required: true,
      default: [],
    }
})        
</script>

<style scoped>
/* 为列表设置固定宽度 */
.list-group {
width: 700px;
}
/* 删除效果 */
.delete {
text-decoration: line-through;
}
</style>